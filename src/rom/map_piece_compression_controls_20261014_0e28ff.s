.setcpu "65816"
.segment "CODE"
.org $28FF
map_control_0e28ff:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
