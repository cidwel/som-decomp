.setcpu "65816"
.segment "CODE"
.org $DBC3
map_control_0edbc3:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
