.setcpu "65816"
.segment "CODE"
.org $10B7
map_control_0f10b7:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
