<?php

/**
 * @file
 * All administration and configuration forms' callbacks and submit handlers.
 */

function multisite_launcher_config_enabled($form, &$form_state) {

  // Define form
  $form = array();

  // Get enabled sites, for default values
  $enabled_sites = multisite_launcher_get_sites('enabled');

  // Define checkbox form items for each folder in /sites directory
  foreach (multisite_launcher_get_sites('all') as $site) {
    $site = _multisite_launcher_strip_dir($site);
    $fstr = _multisite_launcher_fstr($site);

    $form[$fstr] = array(
      '#title' => $site,
      '#type' => 'checkbox',
      '#default_value' => (in_array($fstr, $enabled_sites))
    );
  }

  // Defining submit action
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save Configuration'
  );

  // Return form
  return $form;
}
function multisite_launcher_config_enabled_submit($form, &$form_state) {

  // Save enabled sites to variable
  multisite_launcher_set_enabled_sites($form_state);

  // Message to user
  drupal_set_message(t('The configuration options have been saved.'));
}