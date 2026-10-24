.setcpu "65816"
.segment "CODE"
.org $10F0
map_control_0f10f0:
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
