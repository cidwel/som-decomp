.setcpu "65816"
.segment "CODE"
.org $8DA2
map_control_0f8da2:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
