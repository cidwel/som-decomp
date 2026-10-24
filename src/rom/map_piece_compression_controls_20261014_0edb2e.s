.setcpu "65816"
.segment "CODE"
.org $DB2E
map_control_0edb2e:
    .byte $E7 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
