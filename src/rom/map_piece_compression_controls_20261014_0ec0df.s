.setcpu "65816"
.segment "CODE"
.org $C0DF
map_control_0ec0df:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
