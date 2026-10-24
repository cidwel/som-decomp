.setcpu "65816"
.segment "CODE"
.org $9959
map_control_0f9959:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $6B ; row-distance/count
