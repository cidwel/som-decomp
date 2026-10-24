.setcpu "65816"
.segment "CODE"
.org $DB40
map_control_0edb40:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
