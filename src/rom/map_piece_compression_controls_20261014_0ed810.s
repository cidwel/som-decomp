.setcpu "65816"
.segment "CODE"
.org $D810
map_control_0ed810:
    .byte $EB ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
