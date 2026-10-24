.setcpu "65816"
.segment "CODE"
.org $5F8F
saved_location_formatter = $5A3B
saved_gold_formatter = $5473
saved_time_formatter = $5A87
saved_hero_count_formatter = $5464
native_save_confirmation_summary_targets:
    .word saved_location_formatter, saved_gold_formatter, saved_time_formatter, saved_hero_count_formatter
native_save_confirmation_summary_text_destinations:
    .word $63A0, $65E0, $67E0, $6920
native_save_confirmation_summary_transfer_sizes:
    .word $0240, $0200, $0080, $0040
