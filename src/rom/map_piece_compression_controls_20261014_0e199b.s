.setcpu "65816"
.segment "CODE"
.org $199B
map_control_0e199b:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
