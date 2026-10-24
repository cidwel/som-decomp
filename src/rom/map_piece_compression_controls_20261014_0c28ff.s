.setcpu "65816"
.segment "CODE"
.org $28FF
map_control_0c28ff:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
