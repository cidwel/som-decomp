.setcpu "65816"
.segment "CODE"
.org $410A
map_control_0c410a:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
