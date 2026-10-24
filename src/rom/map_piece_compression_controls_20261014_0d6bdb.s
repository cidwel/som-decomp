.setcpu "65816"
.segment "CODE"
.org $6BDB
map_control_0d6bdb:
    .byte $DF ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $ED ; backreference distance high bits
    .byte $04 ; distance low bit/count
