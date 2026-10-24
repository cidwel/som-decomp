.setcpu "65816"
.segment "CODE"
.org $6C41
map_control_0e6c41:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
