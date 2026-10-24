.setcpu "65816"
.segment "CODE"
.org $0C1C
map_control_0f0c1c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
