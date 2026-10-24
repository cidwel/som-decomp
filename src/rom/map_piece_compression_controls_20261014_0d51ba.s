.setcpu "65816"
.segment "CODE"
.org $51BA
map_control_0d51ba:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E3 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
