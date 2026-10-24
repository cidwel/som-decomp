.setcpu "65816"
.segment "CODE"
.org $02CE
map_control_0f02ce:
    .byte $E2 ; previous-row copy count
