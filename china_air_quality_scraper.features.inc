<?php
/**
 * @file
 * china_air_quality_scraper.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function china_air_quality_scraper_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function china_air_quality_scraper_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function china_air_quality_scraper_node_info() {
  $items = array(
    'air_quality_log' => array(
      'name' => t('Air Quality Log'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
