<?php

/**
 * @file
 * Functions for returning lists of enabled/available sites to use in launcher
 */

function multisite_launcher_get_sites($selector) {
  $sites = array();
  switch ($selector) {
    case 'all':
      $sites = glob(DRUPAL_ROOT . '/sites/*', GLOB_ONLYDIR);
      break;
    case 'enabled':
      $sites = variable_get(MSL . '_sites_enabled', array());
      break;
  }
  return $sites;
}

function _multisite_launcher_clean_sites_array($sites) {
  if(!is_array($sites)) return array();

  // Check if it's a $form_state variable being passed
  else if(array_key_exists('input', $sites)) {

    $array = array();
    $input = $sites['input'];
    $diff = array_diff(array_keys($input), array(
      'op',
      'form_build_id',
      'form_token',
      'form_id'
    ));

    // Add checked sites to array
    foreach($diff as $site) {
      if($input[$site]) $array[] = $site;
    }

    // Return array of sites
    return $array;
  } else {
    return $sites;
  }
}

function multisite_launcher_set_enabled_sites($sites) {
  
  $sites = _multisite_launcher_clean_sites_array($sites);
  variable_set(MSL . '_sites_enabled', $sites);
}

function _multisite_launcher_fstr($site = '', $reverse = FALSE) {
  return (!$reverse ? str_replace('.', '_', $site) : str_replace('_', '.', $site));
}

function _multisite_launcher_strip_dir($site = '') {
  return str_replace(DRUPAL_ROOT . '/sites/', '', $site);
}