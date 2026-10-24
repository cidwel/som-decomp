.setcpu "65816"
.segment "CODE"
.org $D01F
map_control_0ed01f:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
