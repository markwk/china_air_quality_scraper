<?php
/**
 * @file
 * china_air_quality_scraper.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function china_air_quality_scraper_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'latest_air_report';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Latest Air Report';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Latest Air Report';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: AQI */
  $handler->display->display_options['fields']['field_air_aqi']['id'] = 'field_air_aqi';
  $handler->display->display_options['fields']['field_air_aqi']['table'] = 'field_data_field_air_aqi';
  $handler->display->display_options['fields']['field_air_aqi']['field'] = 'field_air_aqi';
  $handler->display->display_options['fields']['field_air_aqi']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PM10 */
  $handler->display->display_options['fields']['field_air_pm10']['id'] = 'field_air_pm10';
  $handler->display->display_options['fields']['field_air_pm10']['table'] = 'field_data_field_air_pm10';
  $handler->display->display_options['fields']['field_air_pm10']['field'] = 'field_air_pm10';
  $handler->display->display_options['fields']['field_air_pm10']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PM2.5 */
  $handler->display->display_options['fields']['field_air_pm25']['id'] = 'field_air_pm25';
  $handler->display->display_options['fields']['field_air_pm25']['table'] = 'field_data_field_air_pm25';
  $handler->display->display_options['fields']['field_air_pm25']['field'] = 'field_air_pm25';
  $handler->display->display_options['fields']['field_air_pm25']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: When */
  $handler->display->display_options['fields']['field_air_when']['id'] = 'field_air_when';
  $handler->display->display_options['fields']['field_air_when']['table'] = 'field_data_field_air_when';
  $handler->display->display_options['fields']['field_air_when']['field'] = 'field_air_when';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Where */
  $handler->display->display_options['fields']['field_air_where_manual_txt']['id'] = 'field_air_where_manual_txt';
  $handler->display->display_options['fields']['field_air_where_manual_txt']['table'] = 'field_data_field_air_where_manual_txt';
  $handler->display->display_options['fields']['field_air_where_manual_txt']['field'] = 'field_air_where_manual_txt';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'air_quality_log' => 'air_quality_log',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'latest-air-report';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Latest Air Report (raw)';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'air-report-export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $export['latest_air_report'] = $view;

  return $export;
}
