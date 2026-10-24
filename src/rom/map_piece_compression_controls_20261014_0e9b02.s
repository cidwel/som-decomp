.setcpu "65816"
.segment "CODE"
.org $9B02
map_control_0e9b02:
    .byte $E0 ; previous-row copy escape
    .byte $AD ; row-distance/count
