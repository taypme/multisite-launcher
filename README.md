# Multisite Launcher

Multisite Launcher is a Drupal 7 module for QA and development workflows. It
lets an administrator select enabled multisite domains, enter one path or
parameter string, and open the corresponding URL on each selected site.

## Installation

Copy or symlink this directory into the Drupal 7 site's `sites/all/modules/`
directory, enable **Multisite Launcher**, and grant the module permissions:

- **Access Multisite Launcher** — use the launcher page.
- **Configure Multisite Launcher** — manage the site list and settings.

The configuration page is available at `/admin/config/multisite_launcher` and
the launcher is available at `/multisite_launcher` after enabling the module.

## How it works

The PHP module discovers site directories under `DRUPAL_ROOT/sites/`, stores
the enabled-site selection with Drupal variables, and attaches
`multisite_launcher.js` to the launcher form. The browser creates links for
each selected site using the entered path and triggers them in new tabs.

## Compatibility and safety

This module targets Drupal 7's procedural module API and is not a Drupal 8+
module. It assumes the configured multisite names are valid local site
directories. Review the generated URLs and browser popup policy before using it
against production sites.
