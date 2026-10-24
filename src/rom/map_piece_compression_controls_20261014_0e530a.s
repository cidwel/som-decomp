.setcpu "65816"
.segment "CODE"
.org $530A
map_control_0e530a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
