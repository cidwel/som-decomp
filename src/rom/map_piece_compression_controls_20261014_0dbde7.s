.setcpu "65816"
.segment "CODE"
.org $BDE7
map_control_0dbde7:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
