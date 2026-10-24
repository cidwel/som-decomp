.setcpu "65816"
.segment "CODE"
.org $CF34
map_control_0dcf34:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
