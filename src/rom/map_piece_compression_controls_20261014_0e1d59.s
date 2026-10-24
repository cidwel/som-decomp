.setcpu "65816"
.segment "CODE"
.org $1D59
map_control_0e1d59:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
