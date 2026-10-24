.setcpu "65816"
.segment "CODE"
.org $846F
map_control_0d846f:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
