.setcpu "65816"
.segment "CODE"
.org $6C41
map_control_0d6c41:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
