.setcpu "65816"
.segment "CODE"
.org $1097
map_control_0f1097:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
