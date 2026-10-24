.setcpu "65816"
.segment "CODE"
.org $3CEF
map_control_0d3cef:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
