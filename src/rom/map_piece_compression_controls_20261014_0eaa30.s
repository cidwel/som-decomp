.setcpu "65816"
.segment "CODE"
.org $AA30
map_control_0eaa30:
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
