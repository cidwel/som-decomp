.setcpu "65816"
.segment "CODE"
.org $EF52
map_control_0eef52:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
