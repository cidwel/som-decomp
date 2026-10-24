.setcpu "65816"
.segment "CODE"
.org $1601
map_control_0c1601:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
