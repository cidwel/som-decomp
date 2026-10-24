.setcpu "65816"
.segment "CODE"
.org $33D5
map_control_0e33d5:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
