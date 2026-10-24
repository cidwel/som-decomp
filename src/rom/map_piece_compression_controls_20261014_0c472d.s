.setcpu "65816"
.segment "CODE"
.org $472D
map_control_0c472d:
    .byte $E9 ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
