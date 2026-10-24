.setcpu "65816"
.segment "CODE"
.org $C02B
map_control_0dc02b:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
