.setcpu "65816"
.segment "CODE"
.org $7CB5
map_control_0c7cb5:
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
