.setcpu "65816"
.segment "CODE"
.org $FC18
map_control_0dfc18:
    .byte $E3 ; previous-row copy count
