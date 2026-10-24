.setcpu "65816"
.segment "CODE"
.org $8CC4
map_control_0f8cc4:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
