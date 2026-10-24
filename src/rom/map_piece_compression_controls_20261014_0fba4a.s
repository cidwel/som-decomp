.setcpu "65816"
.segment "CODE"
.org $BA4A
map_control_0fba4a:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
