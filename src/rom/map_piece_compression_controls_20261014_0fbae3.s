.setcpu "65816"
.segment "CODE"
.org $BAE3
map_control_0fbae3:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
