.setcpu "65816"
.segment "CODE"
.org $C376
map_control_0ec376:
    .byte $E8 ; backreference distance high bits
    .byte $AD ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $AF ; row-distance/count
