.setcpu "65816"
.segment "CODE"
.org $2AEA
map_control_0d2aea:
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
