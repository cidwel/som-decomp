.setcpu "65816"
.segment "CODE"
.org $7DC0
map_control_0d7dc0:
    .byte $E5 ; previous-row copy count
    .byte $DB ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
