.setcpu "65816"
.segment "CODE"
.org $DDC3
map_control_0eddc3:
    .byte $EA ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
