.setcpu "65816"
.segment "CODE"
.org $36D0
map_control_0e36d0:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
