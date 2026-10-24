.setcpu "65816"
.segment "CODE"
.org $60D1
map_control_0f60d1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
