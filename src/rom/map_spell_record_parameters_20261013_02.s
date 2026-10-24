; Cast presentation selected by parameter $88; no pointed payload.
.setcpu "65816"
.segment "CODE"
.org $2B50
.macro cast_presentation selector_04f, presentation_type, frame_index, caster_script, target_script
    .byte selector_04f, presentation_type
    .word frame_index, caster_script, target_script
.endmacro
map_spell_record_parameters_20261013_02:
    cast_presentation $81, $00, $6794, $96ED, $8AC7
