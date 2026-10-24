.setcpu "65816"
.segment "CODE"
.org $B016
map_control_0db016:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
