.setcpu "65816"
.segment "CODE"
.org $A7AF
map_control_0fa7af:
    .byte $E8 ; backreference distance high bits
    .byte $1A ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
