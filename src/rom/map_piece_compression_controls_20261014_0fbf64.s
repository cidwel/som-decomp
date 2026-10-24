.setcpu "65816"
.segment "CODE"
.org $BF64
map_control_0fbf64:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
