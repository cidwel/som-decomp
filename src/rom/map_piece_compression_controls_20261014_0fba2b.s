.setcpu "65816"
.segment "CODE"
.org $BA2B
map_control_0fba2b:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
