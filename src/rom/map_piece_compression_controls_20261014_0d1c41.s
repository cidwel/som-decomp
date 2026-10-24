.setcpu "65816"
.segment "CODE"
.org $1C41
map_control_0d1c41:
    .byte $E0 ; previous-row copy escape
    .byte $88 ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
