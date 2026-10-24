.setcpu "65816"
.segment "CODE"
.org $9687
map_control_0e9687:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0F ; distance low bit/count
