.setcpu "65816"
.segment "CODE"
.org $67EB
map_control_0c67eb:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
