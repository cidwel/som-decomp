; Typed sixteen-entry personality selector table. No graphical payload.
.setcpu "65816"
.segment "CODE"
native_personality_selection_behavior_codes:
    .byte $00, $00, $02, $02, $00, $00, $02, $02
    .byte $01, $01, $03, $03, $01, $01, $03, $03
